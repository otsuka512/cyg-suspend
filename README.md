cyg-suspend
===========

Suspend and Hibernate from cygwin shell script

利用目的
--------

Windows PC をRemote Desktop で使用後に Suspend 状態にしたい場合、
スタートメニューから実行すると即座に通信が切れてしまうため、
次回 Wake on LANをかけてログオンした際に、後片付けが必要となる。

そこで、以下の様な shell script を併用することで、
suspend に入る前と復帰してからの background 処理の停止・開始も
一緒にできるようになる。

    #!/bin/sh
    
    $HOME/bin/service.background stop
    echo "Suspend after 20 seconds"
    sleep 20
    $HOME/bin/cyg-suspend
    
    echo -n "Resume forward [y/n]?"
    read YN
    case "$YN" in
     y|Y) $HOME/bin/service.background start ;;
     *) echo "nothing to do" ;;
    esac

Background service
------------------

backgroundで実行するものとしては、ssh tunnel などがある。
