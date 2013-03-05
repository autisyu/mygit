#工作目录:cat_change_func, 目的生成每个commit的版本
rm ../totalAnalysis/totalVersion ;for i in `ls`;do awk -v v=$i '{print $0" "v}' $i;done>../totalAnalysis/totalVersion;

awk '{print $1" "$3}' totalVersion > linuxCommitWithVersion

awk '{if($2=="change") print $1" "$3}' totalVersion> linuxChangeWithVersion
../sort.py linuxChangeWithVersion linuxChangeWithVersionSort
uniq -c linuxChangeWithVersionSort | sort -n -k1 |awk '{print $2" "$1" "$3}' > linuxChangeWithVersionSortUniqC


#计算每个版本的commit总数
../sort.py linuxCommitWithVersion linuxCommitWithVersionSort
uniq -c linuxCommitWithVersionSort | sort -n -k1 |awk '{print $2" "$1" "$3}' > linuxCommitWithVersionSortUniqC




awk '{if($2=="bug") print $1" "$3}' totalVersion> linuxBugWithVersion
../sort.py linuxBugWithVersion linuxBugWithVersionSort
uniq -c linuxBugWithVersionSort | sort -n -k1 |awk '{print $2" "$1" "$3}' > linuxBugWithVersionSortUniqC



awk '{if($2=="bug") print $1}' totalVersion> linuxBug

awk '{if($2=="change") print $1}' totalVersion> linuxChange

../sort.py linuxBug linuxBugSort

../sort.py linuxChange linuxChangeSort

../sort.py linuxCommit linuxCommitSort


uniq -c linuxChangeSort|awk '{print $2" "$1}' |sort -n -k2>linuxChangeSortUniqC

uniq -c linuxBugSort|awk '{print $2" "$1}' |sort -n -k2>linuxBugSortUniqC


#获取每个commit对应函数的生命周期和commit的版本
../getChangeCommitLife.py linuxFuncDisappearedNamedLifeStartAndEnd1-300 linuxCommitWithVersion > linuxCommitWithVersionAndLife

#生成
#工作目录:linuxTagsAllName,目的计算出消失函数的生命周期
../SearchLifeStartAndEnd.py ../linuxFuncDisappeared ../linuxTagsSortFunc 200 301 > ~/linux-patch-analysis-0108/totalAnalysis/linuxFuncDisappearedLifeStartAndEnd200-301

#获取每个commit对应函数的生命周期和commit的版本

#计算有bug函数的生命周期
../../getChangeCommitLife.py linuxFuncDisappearedNamedLifeStartAndEnd1-300 ../rawData/linuxBug | awk '{print $1" "($3-$2 + 1)}' > linuxFuncDisappearedBugLife

../../getChangeCommitLife.py linuxFuncDisappearedNamedLifeStartAndEnd1-300 ../rawData/linuxChange | awk '{print $1" "($3-$2 + 1)}' > linuxFuncDisappearedChangeLife

#生产既没有bug也没有change的函数
../../union.py ../rawData/linuxBug linuxFuncDisappeared ../rawData/noBug
../../union.py linuxChange noBug noBugAndChange

#计算既有bug又有change的函数,以及相应的bug和change数目
../../notunion.py linuxBug ../Life/linuxFuncDisappeared hasBug
../../notunion.py linuxChange hasBug hasBugAndChange
../../getChangeCommitLife.py linuxBugSortUniqC ../rawData/hasBugAndChange | awk '{print $1" "$2}' > tp
../../getChangeCommitLife.py linuxChangeSortUniqC  tp | awk '{print $1" "$2" "$4}'> hasBugAndChangeUniqC


#计算bug,chang,commit和生命周期的关系

../../getChangeCommitLife.py ../Life/linuxFuncDisappearedNamedLifeStartAndEnd1-300 ../UniqC/linuxBugSortUniqC | awk '{print $1" "($3-$2 + 1)" "$7}'>linuxFuncDisappearedNamedLifeAndBug

../../getChangeCommitLife.py ../Life/linuxFuncDisappearedNamedLifeStartAndEnd1-300 ../UniqC/linuxChangeSortUniqC | awk '{print $1" "($3-$2 + 1)" "$7}'>linuxFuncDisappearedNamedLifeAndChange

../../getChangeCommitLife.py ../Life/linuxFuncDisappearedNamedLifeStartAndEnd1-300 ../UniqC/linuxCommitSortUniqC | awk '{print $1" "($3-$2 + 1)" "$7}'>linuxFuncDisappearedNamedLifeAndCommit


#计算每个版本的增加删除修改的函数个数
bf="v2.6.12-rc2";workdir="../linux-2.6-git-log-p/linuxTagAllName"; for next in `cat linuxTagsSort`;do echo $bf" "$next; ./addDelChange.py $workdir/$bf\_tags_func $workdir/$next\_tags_func cat_change_func/$next\_commit_cat ;bf=$next;done;

#计算出每个版本的bug和change数目
for i in `ls`;do bug=`cat $i|grep "bug$"|wc -l`; change=`cat $i|grep "change$"|wc -l`; echo $i" "$bug" "$change;done;

#计算出每个版本机油bug又有change的函数
for i in `ls`; do ../sort.py $i ../tp ; cnt=`uniq ../tp| awk '{print $1}' | uniq -c | awk '{if($1 == 2) print $0}'|wc -l`; echo $i" "$cnt; done> ../VersionWithBugAndChange

#生成commit预测数据
awk 'BEGIN{bf=" ";cnt=0;nst;nend;bst;bend}{nst=$2;nend = $3;now=$1; if(bf == " " || now == bf) {print $8" "$7;bf=now;cnt++;bst=nst;bend = nend} else {print bst" "bend+1" "cnt"\n"$8" "$7;cnt = 1;bf=now;bst=nst;bend=nend} }END{print bst" "bend+1" "cnt}' commitData.txt> commitResData.txt 

for i `ls|grep '$v';do if [ $i == v2.6.12 ];then before= $i ;continue;fi; next=$i; ../getFileExpectAgain.py $before $next|sort|awk -v b=$before -v n=$next 'BEGIN{before=;now=;cnt=0;total=0}{now=; if(before==||before==now){total+=;cnt++;} else{print before total/cnt;total=;cnt=1};before=now}END{print b nn}';before=$next;done;
for now in `ls|grep v|awk -F '-' '{print $1}'`;do if [ $now == "v2.6.12" ];then before=$now; continue; fi;echo -n $before" "$now" "; cat $now-total-author >> left; sort -u left -o left; ../../getAuthExpect.py left  ../../linuxFunction/$before ../../linuxFunction/$now;before=$now;done;
