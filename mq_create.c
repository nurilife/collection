#include <mqueue.h> // 여기부서 시작입니다.
#include <stdio.h>

int main() {
	mqd_t mqd;
	struct mq_attr attr = {
		.mq_maxmsg = 10,
		.mq_msgsize = 4,
	};

	mq_unlink("/msg_q");
	mqd = mq_open("/msg_q", O_RDWR | O_CREAT,  0666, &attr);
	if (mqd == -1) {
		perror("open error");
		return -1;
	}

	return 0;
} // 여기가 끝입니다.