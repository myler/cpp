#include "ace/Malloc.h"
#include "ace/Log_Msg.h"
#include "ace/Containers.h"  
#include "ace/Malloc_T.h"  
#include "ace/Synch.h"   

typedef char MEMORY_BLOCK[1024];
typedef ACE_Cached_Allocator<MEMORY_BLOCK,ACE_SYNCH_MUTEX> Allocator;

class MessageManager
{
public:
	MessageManager(int n_blocks):
	allocator_(n_blocks),message_count_(0)
	{
	mesg_array_=new char*[n_blocks];
	}

	void allocate_msg(const char *msg)
	{
	mesg_array_[message_count_]=allocator_.malloc(ACE_OS::strlen(msg)+1);
	ACE_OS::strcpy(mesg_array_[message_count_],msg);
	message_count_++;
	}

	void free_all_msg()
	{
	for(int i=0;i<message_count_;i++)
	allocator_.free(mesg_array_[i]);
	message_count_=0;
	}

	void display_all_msg()
	{
	for(int i=0;i<message_count_;i++)
	ACE_OS::printf("%s\n",mesg_array_[i]);
	}
private:
	char **mesg_array_;
	Allocator allocator_;
	int message_count_;
};

int main(int argc, char* argv[])
{
	if(argc<2)
	{
	ACE_DEBUG((LM_DEBUG, "Usage: %s <Number of blocks>\n", argv[0]));
	exit(1);
	}
	int n_blocks=ACE_OS::atoi(argv[1]);
	MessageManager mm(n_blocks);

	while(1)
	{
	ACE_DEBUG((LM_DEBUG,"\n\n\nAllocating Messages\n"));
	for(int i=0; i<n_blocks;i++){
	ACE_OS::sprintf(message,"Message %d: Hi There",i);
	mm.allocate_msg(message);
	}

	ACE_DEBUG((LM_DEBUG,"Displaying the messages\n"));
	ACE_OS::sleep(2);
	mm.display_all_msg();

	ACE_DEBUG((LM_DEBUG,"Releasing Messages\n"));
	ACE_OS::sleep(2);
	mm.free_all_msg();
	}

	return 0;
}