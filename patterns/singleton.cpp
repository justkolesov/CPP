 class Singleton
 {
 private:
 	static Singleton* p_instance;
 	Singleton() {};
 	Singleton(const Singleton&);
 	Singleton& operator=(const Singleton&);
 public:
 	static Singleton* GetInstance(){
 		if(!p_instance)
 		{
 			p_instance  = new Singleton();
 			return p_instance;
 		}
 	}
};
