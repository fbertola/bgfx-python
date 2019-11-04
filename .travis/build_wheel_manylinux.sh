#!/usr/bin/env bash

yum install -y centos-release-scl
yum install -y devtoolset-8-gcc devtoolset-8-gcc-c++ clang cmake ninja-build mesa-libGL-devel

for PYBIN in "cp36-cp36m" "cp37-cp37m" "cp38-cp38m"/opt/python/*/bin; do
    "/opt/python/${PYBIN}/bin/pip" install --user setuptools wheel scikit-build cmake ninja
    "/opt/python/${PYBIN}/bin/python" setup.py bdist-wheel
done

for whl in dist/*.whl; do
    auditwheel repair "$whl" --plat manylinux2010_x86_64 -w /v/wheelhouse/
done
