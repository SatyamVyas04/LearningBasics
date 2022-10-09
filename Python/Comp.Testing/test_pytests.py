import TestFile    # The code to test

def test1():
    assert TestFile.main("2", "10") == 4

def test2():
    assert TestFile.main("4", "0001") == 4
