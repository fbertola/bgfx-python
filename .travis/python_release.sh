#!/usr/bin/env bash

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  yes | sudo port install python$MAC_PYTHON;
  yes | sudo port install py$MAC_PYTHON-pip;
  sudo port select --set python3 python$MAC_PYTHON;
  sudo port select --set pip pip$MAC_PYTHON;
  export PATH=$PATH:$(python3 -c "import site; print(site.USER_BASE)")/bin;
  pip install --user setuptools wheel scikit-build cmake ninja delocate
  pip wheel -w dependencies/bgfx/.build/projects/dist .
  cd dependencies/bgfx/.build/projects/dist || exit
  ls ./*
  for f in ./*.whl; do
    delocate-wheel -w ../../../../../wheelhouse $f
  done
  cd ../../../../.. || exit
  ls wheelhouse/*
else
  docker run -i --rm -v $PWD:/v -w /v -e LINUX_PYTHON=$LINUX_PYTHON --net=host quay.io/pypa/manylinux2014_x86_64 /v/.travis/build_wheels_manylinux.sh
  sudo chown -R $(id -nu):$(id -ng) .
  ls wheelhouse/*
fi
