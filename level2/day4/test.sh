#!/bin/bash

read -p 'please input a num
' num


func (){
    a=${num:0:1}
    b=${num:1:1}
    c=${num:2:1}
    
    d=$((a**3+b**3+c**3))
    echo $d    
    if [ $d = $num ]; then
        echo 是水仙花数
    else
        echo 不是水仙花数
    fi
}

func
