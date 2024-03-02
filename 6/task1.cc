#if defined(USE_GPU) && defined(USE_FLOAT)
	first
#elif defined(USE_GPU) && !defined(USE_FLOAT)
	second

#elif defined(USE_FLOAT) && !defined(USE_GPU)
	third
#else
	forth
#endif
