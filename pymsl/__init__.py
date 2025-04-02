from ctypes import cdll, POINTER, c_void_p, c_char_p, c_bool, Structure, c_uint32, byref, WinDLL, get_last_error
import pprint
import os

std_queue = POINTER(c_void_p)

class MSL:
    class Token(Structure):
        _fields_ = [("value", c_char_p),
                    ("level", c_uint32),
                    ("line", c_uint32)]

        def __repr__(self):
            return f'<{self.type.decode()} token has value {self.value} with level {self.level} at line {self.line}>'

    def __init__(self, path_to_shared_library):
        self.library = cdll.LoadLibrary(path_to_shared_library)

        self.library.tokenize.restype = std_queue
        self.library.tokenize.argtypes = [c_char_p]

        self.library.isempty.restype = c_bool
        self.library.isempty.argtypes = [std_queue]

        self.library.pop_token.restype = MSL.Token
        self.library.pop_token.argtypes = [std_queue]

    def tokenize(self, text):
        l = []
        tokens = self.library.tokenize(text.encode())
        while not self.library.isempty(tokens):
            l.append(self.library.pop_token(tokens).value)
        return l