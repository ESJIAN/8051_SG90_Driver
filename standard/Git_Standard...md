һ��Ϊʲô��Ҫ�ƶ��ύ�淶��
���Ŷ�Э������ʱ��ÿ�����ύ����ʱ����д commit message��
ÿ���˶����Լ�����д��񣬷����������git log, ����˵���廨���ţ�ʮ�ֲ������Ķ���ά����
һ����˵���󳧶���һ�׵��Լ����ύ�淶����������һЩ���Ϳ�Դ��Ŀ�У�commit message ����ʮ��һ�µġ�
��ˣ�������Ҫ�ƶ�ͳһ��׼����ʹ�Ŷ��γ�һ�µĴ����ύ��񣬸��õ���߹���Ч�ʣ���Ϊһ����׷��Ĺ���ʦ��
����ҵ��ͨ�õ� git �ύ�淶����Щ��
1.?commitizen
AngularJS?�� github�� ���ύ��¼��ҵ��������Ͽɣ��𽥱�������á�
��ʽ��
type(scope) : subject
( 1 ) type�����룩 : commit �����ֻ����ʹ�����漸����ʶ��
- feat : �¹���
- fix : �޸�bug
- docs : �ĵ��ı�
- style : �����ʽ�ı�
- refactor : ĳ�����й����ع�
- perf : �����Ż�
- test : ���Ӳ���
- build : �ı���build���� �� grunt������ npm
- revert : ������һ�ε� commit
- chore : �������̻������ߵı䶯
( 2 ) scope����ѡ�� : ����˵�� commit Ӱ��ķ�Χ���������ݲ㡢���Ʋ㡢��ͼ��ȵȣ�����Ŀ��ͬ����ͬ��
( 3 ) subject�����룩 : commit �ļ��������������50���ַ���
commitizen ��һ��׫д�ϸ� Commit message �Ĺ��ߣ�
��ѭ Angular ���ύ�淶��
��װ��
ȫ�ְ�װ commitizen
npm install -g commitizen
������Ŀ�ļ��У������������
commitizen init cz-conventional-changelog --save --save-exact
ʹ�ã�
��?git cz?����ȡ��?git commit����ʹ��git add������ʱ���������ѡ�
�� 1 ��ѡ�� type
[Image]
�� 2 ����д scope��ѡ�
? What is the scope of this change (e.g. component or file name)? (press enter to skip)
core
�� 3 ����д subject
? Write a short, imperative tense description of the change:
set a to b
��ɣ�����?git log?����鿴���Ǹղ��ύ�� commit message�����£�
fix(core): set a to b
�ŵ㣺
- ����ҵ�ڱ�׼�������Ŀʹ�� AngularJS ��commit �淶��
- �ύ���̸��ӹ淶��ʹ�� commitizen �淶���ߣ����ͳһ��
- �ܹ����ɷ��ͳһ�� commit log��type(scope):subject)
ȱ�㣺
- ��Ҫ��װ commitizen ���߰���ʹ��Ŀ���󡢸����ˣ��ʺϴ��Ϳ�Դ��Ŀ��
- �ύ������Լ���ϴ�
- ��һ����ѧϰ�ɱ�
2. ���� git commit ģ��
�������£�
( 1 ) ����ģ���ļ�
����Ŀ�н��� .git_template �ļ������ݿ����Զ��壺
type:
scope:
subject:
( 2 ) ����ģ��
�����������
git config commit.template .git_template // ��ǰ��Ŀ
<!-- git config commit.template .git_template // ȫ������ -->
( 3 ) �ύ����
��ʹ��?git add?��Ӵ���
ʹ��?git commit?����ģ����д
���?git push?���͵�Զ��
�ŵ㣺
- ��������ã�������
- ���÷�ʽ��ֻࣨ����������ļ���
ȱ�㣺
- �����Բÿ�ζ�Ҫ�� vim �༭����дģ��
- �׳���û�пɿ���У�鷽ʽ
�����ƶ��ʺ����ǵ� git commit �ύ�淶
�ڶ������ᵽ������ҵ���ձ�ʹ�õĹ淶��������ȫ�ʺ����ǡ�
��һ�ַ�ʽ�ʺϴ��Ϳ�Դ��Ŀ���������Ҳ�հ��Ƚ��鷳�������ǿ��Խ�� type(scope): subject ���ύ��ʽ��Ҳ�������ͬ����
�ڶ��ַ�ʽ��Ȼ���ɣ�����Ҳ���Ƚ��鷳��Ҫ����ģ�塣
��ˣ�����ֻģ�� type(scope): subject ���ύ��ʽ����ʹ�ù��� or ģ��У�飬������Ծ����ؼ��ɡ�
��ʽ
type: description
1. type ����
type �� commit �����ֻ�������¼��ֱ�ʶ��
- fix: �޸�bug
- add: �¹���
- update: ����
- style : �����ʽ�ı�
- test: ���Ӳ��Դ���
- revert: ������һ�ε�commit
- build: �������߻򹹽����̵ȵı䶯���磺gulp ������ webpack��webpack ������
2. description
description �ǶԱ����ύ�ļ��������
������50���ַ���