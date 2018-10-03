from __future__ import print_function

import pandas as pd

# Import the SMS dataframe

df_sms = pd.read_excel('df_sms.xls', header=0)

# Generate the emoji parsing function

def emoji_parse3(row):

    from emoji import UNICODE_EMOJI

    row['SMSEmojiCount'] = 0
    row['SMSEmojiLabels'] = None

    for emoji in UNICODE_EMOJI.keys():

        if emoji in row['SMSText']:

            row['SMSEmojiCount'] += row['SMSText'].count(emoji)

            if row['SMSEmojiLabels'] == None:
                row['SMSEmojiLabels'] = UNICODE_EMOJI[emoji].replace(':', '')
            elif row['SMSEmojiLabels'] != None:
                row['SMSEmojiLabels'] += ', ' + UNICODE_EMOJI[emoji].replace(':', '')

    return row

# Function that counts the number of emojis present in the text

df_sms = df_sms[pd.notnull(df_sms['SMSText'])].apply(emoji_parse3, axis=1)

# Display the results of the counting
    
print(df_sms.info())
print(df_sms[['SMSEmojiCount']].describe())
print(df_sms[df_sms['SMSDirection'] == 'out']['SMSEmojiLabels'].value_counts())
