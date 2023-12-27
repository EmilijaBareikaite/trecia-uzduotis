#!/bin/bash

# Specify the path to your DMG file
DMG_FILE="/Users/emilijabareikaite/Desktop/galutine.dmg"

# Specify the first destination directory
DESTINATION_DIR1="/Users/emilijabareikaite/Desktop/VU/Emilija-Bareikaite"

# Specify the second destination directory
DESTINATION_DIR2="/Users/emilijabareikaite/Desktop"

# Specify the desired mount point
MOUNT_POINT="/Volumes/galutine"

# Mount the DMG file
hdiutil attach "$DMG_FILE" -mountpoint "$MOUNT_POINT"

# Copy the contents to the first destination directory
cp -r "$MOUNT_POINT"/* "$DESTINATION_DIR1"

# Copy the contents to the second destination directory
cp -r "$MOUNT_POINT"/* "$DESTINATION_DIR2"

# Unmount the DMG
hdiutil detach "$MOUNT_POINT"


