# Error IUSE 100% in CentOS

If error happen, CentOS will not allow user to ``yum install`` more file.

Problem solved: ``sudo rm -rf /var/cache/*``
