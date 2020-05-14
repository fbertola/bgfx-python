#!/usr/bin/env bash

yum install -y centos-release-scl
yum install -y devtoolset-8-gcc devtoolset-8-gcc-c++ clang cmake ninja-build freeglut freeglut-devel libX11-devel mesa-libGLU-devel byacc

for PYBIN in $LINUX_PYTHON; do
    "/opt/python/${PYBIN}/bin/pip" wheel -w /v/dependencies/bgfx/.build/projects/dist /v
done

cd /v/dependencies/bgfx/.build/projects/dist || exit

for whl in ./*.whl; do
    # auditwheel repair "$whl" --plat manylinux2014_x86_64 -w /v/wheelhouse/
    auditwheel show "$whl"
    cp $whl /v/wheelhouse
done
