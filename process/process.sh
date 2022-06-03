# 후면처리
# 명령어 &

(sleep 100; echo done) &
find . - name test.c -print &
jobs # 어떤 일을 하고 있는 지

# process

ps # 현재 존재하는 프로세스들의 실행 상태를 요약해서 출력

ps -ef # 전체
# -e:모든 사용자 프로세스 정보를 출력
# -f:프로세스에 대한 좀 더 자세한 정보를 출력

ps -aux
# -a: 모든 사용자의 프로세스를 출력
# -u:프로세스에 대한 좀 더 자세한 정보를 출력
# -x:더 이상 제어 터미널을 갖지 않은 프로세스들도 함께 출력

ps -ef |grep node

# sleep

sleep 초
(echo 시작; sleep 5; echo 끝)

# kill

kill [-시그널] 프로세스번호
kill 1230