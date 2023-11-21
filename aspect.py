import ctypes
import numpy as np
import os

# relativen Path finden
#skript_verzeichnis = os.path.dirname(os.path.abspath(__file__))
#os.chdir(skript_verzeichnis)
#bibliothek_pfad = os.path.join(skript_verzeichnis, "lib", "build","libgradient.so")


# Load the C library
lib = ctypes.CDLL("lib/build/aspect.so")

# Define the argument and return types for the C function
lib.aspect.argtypes = [
    ctypes.c_int,    # rows
    ctypes.c_int,    # cols
    np.ctypeslib.ndpointer(dtype=np.double),  # input_matrix
    np.ctypeslib.ndpointer(dtype=np.double)   # output_matrix
]
lib.aspect.restype = None

def aspect(input_matrix):
    rows, cols = input_matrix.shape
    output_matrix = np.zeros_like(input_matrix)

    # Call the C function
    lib.aspect(rows, cols, input_matrix, output_matrix)

    return output_matrix
