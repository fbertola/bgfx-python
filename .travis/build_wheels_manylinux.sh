#!/usr/bin/env bash

yum install -y centos-release-scl
yum install -y devtoolset-8-gcc devtoolset-8-gcc-c++ clang cmake ninja-build mesa-libGL-devel byacc

for PYBIN in "cp37-cp37m"; do
    "/opt/python/${PYBIN}/bin/pip" wheel -w /v/dist /v
done

for whl in dist/*.whl; do
    auditwheel repair "$whl" --plat manylinux2010_x86_64 -w /v/wheelhouse/
done
