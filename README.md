# MiniDB C

Pequeno armazenamento persistente escrito em **C**, usando arquivo binário de registros de tamanho fixo. O programa implementa CRUD por linha de comando e marcação lógica de exclusão.

## Compilar
```bash
make
```

## Usar
```bash
./minidb init
./minidb insert 1 "Ana Silva" ana@email.com
./minidb insert 2 "João Lima" joao@email.com
./minidb get 1
./minidb list
./minidb delete 2
```

O arquivo é salvo em `data/records.dat`.

## Teste rápido
```bash
bash tests/test.sh
```
