# Splity
This is demonstation of string slicing in python

# Operating System Supported
+ Linux

# Requirements
+ python3
+ argparse
+ colorama
+ pynimations
+ pbars
+ termisize


# How to Run
+ Change the `config.py` file in splity
```python
// coder info
CODER_NAME = "Gurkirat Singh"
SUBMITTED_TO = "Mr. BV Verma"
INSTITUTION = "MDU Rohtak"

CHUNK_SIZE = 20
DESCRIPTION = "Splity is a file splitter and file joiner utility"
SPLIT_EXT = "part"
```

+ run the  `main.py`
```
python3 main.py -h
```
# Help
```
usage: main.py [-h] [-k] [-o OUTPUT_DIR] [--about] [--split FILENAME.EXT]
               [--join FILENAME.EXT] [--chunk CHUNK_SIZE]

Splity is a file splitter and file joiner utility

optional arguments:
  -h, --help            show this help message and exit
  -k, --keep            if this flag passed, it will keep .part files
                        default : False
  -o OUTPUT_DIR, --output-dir OUTPUT_DIR
                        sets the output directory of splitted files
                        default : /home/terabyte/GIT_REPO/educational_projects/PYTHON
  --about               show about text message and exit
  --split FILENAME.EXT  accepts filename to split
  --join FILENAME.EXT   accepts filename to join in same folder
  --chunk CHUNK_SIZE    accept a non zero chunk size in bytes.
                        default : 20 bytes

```