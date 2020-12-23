import ctypes
from array import ArrayType
from typing import Any

try:
    import numpy

    _is_numpy_array = lambda obj: type(obj) is numpy.ndarray
except Exception:
    _is_numpy_array = lambda obj: False


def as_void_ptr(obj: Any) -> ctypes.py_object:
    """
    Creates a Python Capsule to pass 'void *' arguments to C++ APIs.
    Caveat: for other types of pointers, use the `ctypes` interface
    or `cppyy.nullptr` for NULL pointers.

    :param obj: the referenced object
    :return: a Python Capsule representing a pointer to the object
    """
    ctypes.pythonapi.PyCapsule_New.restype = ctypes.py_object
    ctypes.pythonapi.PyCapsule_New.argtypes = [
        ctypes.c_void_p,
        ctypes.c_char_p,
        ctypes.c_void_p,
    ]

    if type(obj) == ArrayType:
        obj = obj.buffer_info()[0]

    if _is_numpy_array(obj):
        obj = obj.ctypes.data_as(ctypes.POINTER(ctypes.c_void_p))

    if type(obj) != ctypes.c_void_p:
        obj = ctypes.cast(obj, ctypes.c_void_p)

    capsule = ctypes.pythonapi.PyCapsule_New(obj, None, None)

    return capsule
