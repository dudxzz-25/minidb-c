#!/usr/bin/env bash
set -euo pipefail
make clean >/dev/null 2>&1 || true
make >/dev/null
./minidb init >/dev/null
./minidb insert 1 "Ana Silva" ana@example.com >/dev/null
./minidb insert 2 "Joao Lima" joao@example.com >/dev/null
./minidb get 1 | grep -q "Ana Silva"
[ "$(./minidb list | wc -l)" -eq 2 ]
./minidb delete 2 >/dev/null
[ "$(./minidb list | wc -l)" -eq 1 ]
echo "MiniDB tests passed."
