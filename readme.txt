plasma-effect/plasma_repository

VC++12.0で自分で使うようにライブラリを再構築してる
VC++12.0以外で動作確認はする気がないので注意
あとboost1.56.0必須
中身はtest_main.cpp以外全部boostソフトウェアライセンス、test_main.cppはパブリックドメインで

使い方
このディレクトリとboost1.56.0をパスに渡す


--以下自分用メモ(readmeに書くなバカタレ)--
plasma.stringの満たす要件
(1)以下のメンバ関数を持つ
size_t size()const//保持してる文字列のサイズ
(2)以下のメンバ型を持つ
value_type//文字の型
type//自分の型
basic_string_tag//value_typeと同じ
(3)input_iterator及びそれに関する関数を持つ
input_iteratorはvalue_typeがTであること
