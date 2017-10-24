from libs import dependency, panel


if __name__ == '__main__':
    dependency.chk()
    a = panel.Panel("lol")
    a.makepanel()
    a.deploy()
