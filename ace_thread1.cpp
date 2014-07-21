#include "ace/Thread.h"
#include "ace/Synch.h"
#include "ace/Log_Msg.h"

static int number = 0;
static int seed = 0;

static void *worker(void *arg)
{
	ACE_UNUSED_ARG(arg);
	ACE_DEBUG((LM_DEBUG, "Thread (%t) Created to do some work"));
	::number++;
	ACE_DEBUG((LM_DEBUG, " and number is %d\n", ::number));

	ACE_OS::sleep(ACE_OS::rand() % 2);
	ACE_DEBUG((LM_DEBUG,
		"\t\t Thread (%t) Done! \t The number is now: %d\n", ::number));

	return 0;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ACE_DEBUG((LM_DEBUG, "Usage: %s <number of threads>\n", argv[0]));
		ACE_OS::exit(1);
	}

	ACE_OS::srand(::seed);

	int n_threads = ACE_OS::atoi(argv[1]);
	ACE_thread_t *threadID = new ACE_thread_t[n_threads + 1];
	ACE_hthread_t *threadHandles = new ACE_hthread_t[n_threads + 1];
	if (ACE_Thread::spawn_n(threadID,
		n_threads,
		(ACE_THR_FUNC)worker,
		0,
		THR_JOINABLE | THR_NEW_LWP,
		ACE_DEFAULT_THREAD_PRIORITY,
		0, 0, threadHandles) == -1)
	{
		ACE_DEBUG((LM_DEBUG, "Error in spawning thread\n"));
	}

	for (int i = 0; i < n_threads; ++i)
	{
		ACE_Thread::join(threadHandles[i]);
	}

	return 0;
}