#!/usr/bin/env bash

if [[ $(uname) == "Darwin" ]]; then
  python3 setup.py bdist_wheel
  ls dist/*
  for f in dist/*.whl; do
    delocate-wheel -w wheelhouse $f
  done
  ls wheelhouse/*
else
  for f in dist/*.whl; do
    docker run -i --rm -v $PWD:/v -w /v --net=host quay.io/pypa/manylinux2010_x86_64 /v/.travis/build_wheels_manylinux.sh
  done
  sudo chown -R $(id -nu):$(id -ng) .
  ls wheelhouse/*
fi
