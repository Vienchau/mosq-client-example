#!/bin/sh
#Exec make command
make
# Add execute permission
chmod +x ./bin/publisher-client
# Compress everything we need to tar.gz
tar -czvf app.tar.gz ./bin/publisher-client
# Transfer file
curl --upload-file app.tar.gz https://cpek.fpt.vn/fs-tx/app.tar.gz