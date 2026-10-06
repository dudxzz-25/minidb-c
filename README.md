# MiniDB C

<p align="center">
  <img alt="C" src="https://img.shields.io/badge/C17-Systems-A8B9CC?logo=c&logoColor=black">
  <img alt="GCC" src="https://img.shields.io/badge/GCC-Build-333333">
  <img alt="Make" src="https://img.shields.io/badge/Make-Automation-555555">
  <a href="https://github.com/dudxzz-25/minidb-c/actions/workflows/ci.yml"><img alt="CI" src="https://github.com/dudxzz-25/minidb-c/actions/workflows/ci.yml/badge.svg"></a>
</p>


[![CI](https://github.com/dudxzz-25/minidb-c/actions/workflows/ci.yml/badge.svg)](https://github.com/dudxzz-25/minidb-c/actions/workflows/ci.yml)

Mini armazenamento persistente escrito em **C**, utilizando arquivo binário com registros de tamanho fixo e uma interface CRUD por linha de comando.

## 🎯 Objetivo

Explorar conceitos de baixo nível relacionados a:

- structs;
- arquivos binários;
- leitura e escrita aleatória;
- persistência;
- CRUD;
- exclusão lógica;
- compilação e testes via shell.

## 🛠️ Stack

**C17 · GCC · Make · Bash**

## 🗃️ Estrutura do registro

Cada registro armazena:

- ID numérico;
- flag de registro ativo;
- nome;
- e-mail.

A exclusão é **lógica**: o registro permanece fisicamente no arquivo, mas é marcado como inativo.

## 📂 Estrutura

```text
minidb-c/
├── src/
│   └── main.c
├── tests/
│   └── test.sh
├── Makefile
└── README.md
```

## ▶️ Compilar

```bash
make
```

## 💻 Uso

```bash
./minidb init
./minidb insert 1 "Ana Silva" ana@email.com
./minidb insert 2 "João Lima" joao@email.com
./minidb get 1
./minidb list
./minidb delete 2
```

O arquivo é armazenado em:

```text
data/records.dat
```

## 🧪 Testes

```bash
bash tests/test.sh
```

O teste executa compilação, inicialização, inserção, consulta, listagem e exclusão.

## ⚠️ Limitações

O formato binário é propositalmente simples e não implementa índices, transações, compactação, concorrência ou portabilidade entre arquiteturas diferentes. O foco é demonstrar fundamentos de persistência em C.

---

Desenvolvido por **Eduardo de Toledo Dias**.

[Portfólio](https://dudxzz-25.github.io/portfolio-web/) · [GitHub](https://github.com/dudxzz-25) · [LinkedIn](https://www.linkedin.com/in/eduardo-de-toledo-dias-880b9834b/)