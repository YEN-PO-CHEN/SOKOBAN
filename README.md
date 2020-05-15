# SOKOBAN 實作

## CORE
- Programming language : cpp
- Programming language version gcc 7.1.0
- Qt version : Qt 5.14.1
- Qt Creator version :4.11.1

## How to play
- 和一般倉庫番玩法相同

## Basic

1. Build map
    - Map 6 x 6(squares)
    - storage location : 3
    - box : 3

2. Player can be controlled 
3. Playable & follow the rules
4. Restart game
    - 當我動第一步的時候，restart 才會出現。
5. Levels
    - 2 levels
    - Can go to next level when clear the stage

## Feature
#### Main MENU:
- 離開遊戲(EXIT)
- 開始遊戲(START)
    - 當點選遊戲開始時，會跳出遊戲玩法，在按出Next時，則會跳出LEVEL1與LEVEL2,得以選擇進入哪一關。

#### The number od steps:
- 顯示在右下角。

#### Other special methods:
- 當我經過地圖上某一點後，便會是Special End 進入下一關。

## Bonus
1. 角色在左右移動時，圖片會左右移動。
2. 當角色碰到狗狗後，咖波會咬住狗狗然後再移動。
3. 可以在遊戲進行的時候，變換主題，有兩種主題能夠互相切換。
4. 當箱子被推到結束點的時候，下面的黃色星星便會亮起。
5. 當箱子被推到結束點的時候，箱子會變暗。
6. 當隱藏的點被採到的時候， 下面的紅色星星便會亮起。
7. 加入聲音
    - 行走時
    - 正確通關時
    - 採到SPECIAL END時
    - 吃到狗狗
    - 按按鈕時。
=======
## 圖片來源(圖片非做商業用途)
- 亞拉 <https://home.gamer.com.tw/homeindex.php?owner=c11403>
- 網路資料
- 小森平的免費音效 <https://taira-komori.jpn.org/freesoundtw.html>

