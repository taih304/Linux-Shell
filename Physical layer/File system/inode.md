``ln``: make links between files

``ln source_file.txt target_file.txt``: ``target_file.txt`` now is the hard link of ``source_file.txt``, i.e a copied of ``source_file.txt``, has the same inode with ``source_file.txt``. Removing ``source_file.txt`` gives no effect to ``target_file.txt``

``ln -s source_file.txt target_file.txt``: ``target_file.txt`` now is the symbolic link (also called soft link) of ``source_file.txt``. ``target_file.txt`` now has different inode with ``source_file.txt``. Its file type now is ``symbolic link`` (check by ``file``). Removing ``source_file.txt`` makes ``target_file.txt`` unable to read.