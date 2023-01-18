# DockerでPlantUMLを使う前の設定内容
0. vscodeの拡張機能入れる
- PlantUMLで検索してInstall

1. docker-composeをbuildしなおす
> $ docker-compose build

2. docker-composeをスタートする
> $ docker-compose up -d

-dなしでもスタート可能。
-dがあることでバックグラウンドで処理するよ、みたいなイメージ

3. vscodeの設定画面を開く

設定画面のイメージの参考：
https://qiita.com/1021ky@github/items/e11948eaaa8a141068d3#visual-studio-code%E3%81%AEplantuml%E3%81%AE%E8%A8%AD%E5%AE%9A

ただし、設定内容違うので下記参照の上設定

```
設定画面を開いて以下の設定をします。（windowsなら"ctrl + ,", macなら"⌘ + ,"で開きます）
plantumlと検索キーワードを入れると設定項目が表示されます。

Plantuml: previewAutoUpdateにチェック
Plantuml: RenderをLocalに選択
Plantuml: Serverをhttp://localhost:8083/ に設定
```

4. 実際に使ってみる
- Visual Studio Codeのコマンドパレットを開く
    - windowsなら"ctrl + shift + p"
    - macなら"⌘ + shift + p"
- PlantUMLと入力
- "PlantUML: カーソル位置のダイアグラムをプレビュー"を選択