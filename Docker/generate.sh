#!/bin/bash

sudo podman build --tag docker.io/diehlpk/modern-cpp-base:latest -f ./Dockerfile
sudo podman login docker.io
id=$(sudo podman inspect --format="{{.Id}}" docker.io/diehlpk/modern-cpp-base:latest)
sudo podman push "$id" docker://diehlpk/modern-cpp-base:latest
