import idaapi
import idautils
import idc

def do_rename(l):
    straddr, strname = l.strip().split(':')

    if straddr[2:] in strname:
        return

    eaaddr = int(straddr, 16)
    idc.MakeCode(eaaddr)
    idc.MakeFunction(eaaddr)
    idc.MakeNameEx(eaaddr, strname, idc.SN_NOWARN)

def load_joker_labels(filename):
    f = open(filename, "r")
    for l in f:
        do_rename(l)
    f.close()

