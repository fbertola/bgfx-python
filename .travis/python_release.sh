#!/usr/bin/env bash

if [[ $(uname) == "Darwin" ]]; then
  pip3 wheel -w dependencies/bgfx/.build/projects/dist
  cd dependencies/bgfx/.build/projects/dist || exit
  ls ./*
  for f in ./*.whl; do
    delocate-wheel -w ../../../../../wheelhouse $f
  done
  cd ../../../../.. || exit
  ls wheelhouse/*
else
  docker run -i --rm -v $PWD:/v -w /v --net=host quay.io/pypa/manylinux2010_x86_64 /v/.travis/build_wheels_manylinux.sh
  sudo chown -R $(id -nu):$(id -ng) .
  ls wheelhouse/*
fi
