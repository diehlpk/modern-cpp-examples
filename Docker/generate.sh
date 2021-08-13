#!/bin/bash

sudo podman build --tag docker.io/diehlpk/siam-review-base:latest -f ./Dockerfile
sudo podman login docker.io
id=$(sudo podman inspect --format="{{.Id}}" docker.io/diehlpk/siam-review-base:latest)
sudo podman push $id docker://diehlpk/siam-review-base:latest
