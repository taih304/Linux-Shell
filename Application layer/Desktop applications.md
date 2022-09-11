## GUI setup

``Ctrl+Alt+F1`` to ``Ctrl+Alt+F6``: enter terminal from ``tty1`` to ``tty6``, which is also known as text terminal.

``Ctrl+Alt+F7``: switch back to desktop and terminal ``tty``.

### screen

The ``screen`` package is pre-installed on most Linux distros nowadays. Install: ``sudo apt install screen``

To end ``screen``: ``Ctr+A+D``.

### Other commands

``xrandr --size 1366x768``: Change size of current screen to ``1366x768``

``\033[8;h;wt`` can be used to change the size of the current running terminal. ``\033`` is the ASCII control character ``ESC``, and ``h`` and ``w`` are height and width in decimal.

```sh
printf '\033[8;64;240t' #must have ''
```

## Spreadsheet

``libreoffice --writer file.odt`` or ``libreoffice --writer file.doc: Open libreoffice doc``

LibreOffice use LibreOffice Basic, which is the derivatives of OpenOffice Basic, to import Macro.

## Visual Studio Code

To preview and export Markdown efifciently in Visual Studio Code, use ``Markdown Preview Enhanced`` by Yiyi Wang. 

Install: 

Launch VS Code Quick Open (Ctrl+P), paste the following command, and press enter:

``ext install shd101wyy.markdown-preview-enhanced``
