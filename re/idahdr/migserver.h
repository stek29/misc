struct routine_descriptor {
	mig_impl_routine_t	impl_routine;	/* Server work func pointer   */
	mig_stub_routine_t	stub_routine;	/* Unmarshalling func pointer */
	unsigned int		argc;			/* Number of argument words   */
	unsigned int		descr_count;	/* Number complex descriptors */
	routine_arg_descriptor_t
						arg_descr;		/* pointer to descriptor array*/
	unsigned int		max_reply_msg;	/* Max size for reply msg     */
};

typedef struct routine_descriptor *routine_descriptor_t;
typedef void (*mig_stub_routine_t)(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);
typedef mig_stub_routine_t mig_routine_t;
typedef mig_routine_t (*mig_server_routine_t)(mach_msg_header_t *InHeadP);

typedef struct mig_subsystem {
	mig_server_routine_t server;		/* pointer to demux routine	*/
	mach_msg_id_t		 start;			/* Min routine number	    */
	mach_msg_id_t		 end;			/* Max routine number + 1   */
	mach_msg_size_t		 maxsize;		/* Max reply message size   */
	vm_address_t		 reserved;		/* reserved for MIG use	    */
	mig_routine_descriptor
						 routine[];	/* Routine descriptor array */
} *mig_subsystem_t;