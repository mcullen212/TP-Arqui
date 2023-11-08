#!/bin/bash

# Ruta al archivo JSON
json_file="task.json"

# Obtener la ruta del archivo .qcow2 desde el JSON
qcow2_file=$(jq -r '.tasks[0].args[1]' "$json_file")

# Directorio del archivo JSON
json_directory=$(dirname "$json_file")

# Construir la ruta completa al archivo .qcow2
qcow2_path="${json_directory}/${qcow2_file}"

# Construir el comando de QEMU
qemu_command="qemu-system-x86_64 -hda \"$qcow2_path\" -m 512 -soundhw pcspk"

# Ejecutar QEMU
eval "$qemu_command"

