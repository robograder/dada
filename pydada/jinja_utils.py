"""
Utils for using jinja within pb grammars
"""

def pb_word_list(words):
    """
    given list of words ["a", "b", ...]
    returns '"a " |\n"b " |'
    """
    return "|\n".join('"%s " ' % w for w in words)
