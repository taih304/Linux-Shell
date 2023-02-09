AsciiDoc document can be generated to any chosen format like HTML, PDF,... by CLI or by AsciiDoc extension on VS code.

## CLI

```sh
asciidoctor -o test test.adoc
```

Generate file ``test`` from ``test.adoc``. ``test`` will then have HTML type.

To generate PDF file, use ``asciidoctor-pdf``

Install 

```sh
sudo gem install rouge #Install rouge first
```

```sh
sudo apt install ruby-asciidoctor-pdf
```

**Note**: If ``rouge`` is not installed, when running ``asciidoctor-pdf`` command, there will be error:

```
asciidoctor: WARNING: optional gem 'rouge' is not available. Functionality disabled.
asciidoctor: FAILED: required gem 'rouge' is not available. Processing aborted.
  Use --trace for backtrace
```

To generate the PDF file:

```sh
asciidoctor-pdf test.adoc
```

File ``test.pdf`` will be generate and will have a format like a PDF book.

## AsciiDoc extension

The AsciiDoc extension on VScode allows user to preview the adoc file and generate it to the chosen format.

To generate a adoc file to a chonse format, like PDF, in that ``adoc`` file, press ``Ctr+Shift+P`` or ``F1``, then choose **Export document as PDF**.
