#!/usr/bin/env bash

python3 setup.py bdist_wheel
ls dist/*

if [[ $(uname) == "Darwin" ]]; then
  for f in dist/*.whl; do
    delocate-wheel -w wheelhouse  $f
  done
  ls wheelhouse/*
else
  for f in dist/*.whl; do
    docker run -i --rm -v $PWD:/v -w /v --net=host quay.io/pypa/manylinux2010_x86_64 bash -x -e auditwheel repair --plat manylinux2010_x86_64 $f
  done
  sudo chown -R $(id -nu):$(id -ng) .
  ls wheelhouse/*
fi