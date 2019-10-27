#!/usr/bin/env bash

if [[ ( ${TRAVIS_BRANCH} == "master" ) && ( ${TRAVIS_EVENT_TYPE} != "pull_request" ) ]]; then
  for entry in wheelhouse/bgfx_python-*.whl ; do
    if [[ $(uname) == "Darwin" ]]; then
      shasum -a 256 $entry
    else
      sha256sum $entry
    fi

    STATUS=$(curl -T $entry -ufbertola:$BINTRAY_API_KEY https://api.bintray.com/content/fbertola/bgfx-python-wheels/tensorflow-io-release/${TRAVIS_BUILD_NUMBER}/$entry)

    if [[ "$STATUS" -ne 200 ]] ; then
      echo "Upload to Bintray: $STATUS"
      exit 1
    fi
  done
fi