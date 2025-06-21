
# Bashling

`Bashling` is a command-line shell implemented in C that emulates the core behavior of GNU Bash. It allows users to interact with their system by entering commands through a terminal interface, parsing and executing them with support for features like piping, redirection, environment variables, and script execution. The prompt also displays the current Git branch when inside a repository, offering a more informative user experience.

## 🚀 Features

- **Command Execution**: Supports running external programs and scripts with full argument handling and path resolution.

- **Built-in Commands**: Includes implementations of essential Bash built-ins like cd, pwd, echo, env, unset, export, and exit.

- **Script Support**: Capable of running both Bash and shell scripts directly, parsing each line as standard input.

- **Piping**: Handles Unix-style pipes (|) with proper parsing and error detection for invalid or incomplete pipe sequences.

- **Redirection Handling**: Supports input (`<`), output (`>`), append (`>>`), and heredoc (`<<`) redirections with accurate file descriptor control.

- **Heredoc Input**: Fully interactive heredoc support with optional variable expansion, depending on delimiter quoting.

- **Variable Expansion**: Expands environment variables (e.g., `$HOME`, `$?`) accurately during parsing and command evaluation.

- **Quote Management**: Correctly handles single and double quotes to preserve literal or expandable content as expected.

- **Prompt Customization**: Displays the current Git branch directly in the prompt when inside a Git repository, enhancing context awareness.

- **Signal Handling**: Reacts to signals like SIGINT (Ctrl+C) gracefully, preserving shell stability during interruptions.

- **Error Reporting**: Offers descriptive error messages for syntax issues, unknown commands, invalid paths, and redirection failures.

## ⚠️ Limitations

Currently, the following Bash features are not yet supported:

- **Logical operators**: `&&`, `||`

- **Background execution**: `&`

- **Subshells**: `()`

- **Globbing/wildcards**: `*`

## 🗂️ Project Structure

The project is organized into logical modules, each handling a core part of the shell's functionality:
```sh
.
├── LICENSE
├── Makefile
├── README.md
├── core.c
├── core.h
├── dependencies
│   ├── executions
│   │   ├── builtin_export.c
│   │   ├── close_prgm.c
│   │   ├── execute_cmd.c
│   │   ├── execute_pipes.c
│   │   └── ...
│   ├── libft
│   │   ├── Makefile
│   │   ├── ft_lstdelone.c
│   │   ├── ft_lstiter.c
│   │   ├── ft_lstlast.c
│   │   └── ...
│   ├── modules
│   │   ├── env_controls.c
│   │   ├── env_init.c
│   │   ├── prompt.c
│   │   ├── replace_all_words.c
│   │   └── ...
│   └── parsing
│       ├── check_separator.c
│       ├── cmd_tree_ops.c
│       ├── extract_redirections.c
│       ├── heredoc.c
│       ├── input_split.c
│       └── ...
└── subject.pdf

6 directories, 80 files
```

## 🛠️ Getting Started

Follow these steps to install, build, and run `bashling` on a Linux system.

- ### 📦 Prerequisites

    Make sure the following packages are installed:

    - **Debian-based (Ubuntu, Linux Mint, etc.)**:

        ```sh
        sudo apt update && sudo apt install build-essential libreadline-dev
        ```
    - **Arch-based (Arch, Manjaro, etc.)**:

        ```sh
        sudo pacman -S base-devel readline
        ```

- ### ✅ Installation

    - **Build Instructions**:

        - **1- Clone the Repository**:

            ```sh
            git clone https://github.com/oussamakami/bashling
            cd bashling
            ```

        - **2- Build the Project**:

            ```sh
            make
            ```

    - **Run the Shell**:

        Once built, you can start the shell with:

        ```sh
        ./bashling
        ```
## 🗑️ Uninstall

- **To remove all build object files**:

    ```sh
    make clean
    ```

- **To remove all build objects including the executable binary**:

    ```sh
    make fclean
    ```
## 💻 Usage

```sh
ubuntu@dev-server:~/bashling (master)$ pwd
/home/ubuntu/bashling

ubuntu@dev-server:~/bashling (master)$ ls -la dependencies/
total 24
drwxrwxr-x 6 ubuntu ubuntu 4096 Jun  8 21:45 .
drwxrwxr-x 4 ubuntu ubuntu 4096 Jun 21 04:59 ..
drwxrwxr-x 2 ubuntu ubuntu 4096 Jun 21 04:57 executions
drwxrwxr-x 2 ubuntu ubuntu 4096 Jun 21 04:57 libft
drwxrwxr-x 2 ubuntu ubuntu 4096 Jun 21 04:57 modules
drwxrwxr-x 2 ubuntu ubuntu 4096 Jun 21 04:57 parsing

ubuntu@dev-server:~/bashling (master)$ export NAME=world
ubuntu@dev-server:~/bashling (master)$ echo "Hello, $NAME"
Hello, world

ubuntu@dev-server:~/bashling (master)$ unset NAME
ubuntu@dev-server:~/bashling (master)$ echo "Hello, $NAME"
Hello, 

ubuntu@dev-server:~/bashling (master)$ echo "Hello" > hello.txt
ubuntu@dev-server:~/bashling (master)$ cat < hello.txt
Hello

ubuntu@dev-server:~/bashling (master)$ echo "World" >> hello.txt
ubuntu@dev-server:~/bashling (master)$ cat hello.txt
Hello
World

ubuntu@dev-server:~/bashling (master)$ echo "foo bar" | tr a-z A-Z | rev
RAB OOF

ubuntu@dev-server:~/bashling (master)$ cat << EOF
> This is a heredoc
> With multiple lines
> and $HOME expansion
EOF
This is a heredoc
With multiple lines
and /home/ubuntu expansion

ubuntu@dev-server:~/bashling (master)$ env | grep HOME
HOME=/home/ubuntu

ubuntu@dev-server:~/bashling (master)$ echo $?
0

ubuntu@dev-server:~/bashling (master)$ ^C
# Prompt remains stable after Ctrl+C

ubuntu@dev-server:~/bashling (master)$ exit
```

## 🤝 Authors

- Oussama Kamili [@oussamakami](https://github.com/oussamakami)

- Yassine Ait Oulahyani [@nenuser1337](https://github.com/nenuser1337)

## 📝 License

This Project Is Licensed Under &copy; [**MIT License**](https://github.com/oussamakami/bashling/blob/master/LICENSE)