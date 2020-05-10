import ctypes
import math

import numpy as np


def sub(v1, v2):
    return [v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]]


def cross(v1, v2):
    v1x = v1[0]
    v1y = v1[1]
    v1z = v1[2]
    v2x = v2[0]
    v2y = v2[1]
    v2z = v2[2]
    return [
        (v1y * v2z) - (v1z * v2y),
        (v1z * v2x) - (v1x * v2z),
        (v1x * v2y) - (v1y * v2x),
    ]


def length(vec3):
    return math.sqrt(vec3[0] * vec3[0] + vec3[1] * vec3[1] + vec3[2] * vec3[2])


def normalize(vec3):
    l = length(vec3)
    return [vec3[0] / l, vec3[1] / l, vec3[2] / l]


def look_at(eye, at, up):
    """Constructs look-at matrix for right handed coordinate system."""
    view = normalize(sub(at, eye))
    right = normalize(np.cross(up, view))

    up = np.cross(view, right)

    view = (ctypes.c_float * 16)(
        *[
            right[0],
            up[0],
            view[0],
            0.0,
            right[1],
            up[1],
            view[1],
            0.0,
            right[2],
            up[2],
            view[2],
            0.0,
            -np.dot(right, eye),
            -np.dot(up, eye),
            -np.dot(view, eye),
            1.0,
        ]
    )

    return view


def proj(fov_y, aspect, near, far):
    height = 1.0 / math.tan(math.radians(fov_y) * 0.5)
    width = height * 1.0 / aspect
    diff = far - near
    aa = far / diff
    bb = near * aa

    return (ctypes.c_float * 16)(
        *[
            width,
            0.0,
            0.0,
            0.0,
            0.0,
            height,
            0.0,
            0.0,
            0.0,
            0.0,
            aa,
            1.0,
            0.0,
            0.0,
            -bb,
            0.0,
        ]
    )


def ortho(left, right, bottom, top, near, far):
    aa = 2.0 / (right - left)
    bb = 2.0 / (top - bottom)
    cc = 1.0 / (far - near)
    dd = (left + right) / (left - right)
    ee = (top + bottom) / (bottom - top)
    ff = near / (near - far)

    return (ctypes.c_float * 16)(
        *[aa, 0.0, 0.0, 0.0, 0.0, bb, 0.0, 0.0, 0.0, 0.0, cc, 0.0, dd, ee, ff, 1.0]
    )


def rotate_xy(rot_x, rot_y):
    sx, cx = np.sin(rot_x), np.cos(rot_x)
    sy, cy = np.sin(rot_y), np.cos(rot_y)

    return np.array(
        (
            (cy, 0.0, sy, 0.0),
            (sx * sy, cx, -sx * cy, 0.0),
            (-cx * sy, sx, cx * cy, 0.0),
            (0.0, 0.0, 0.0, 1.0),
        ),
        dtype=np.float32,
    )
