#include "Slist.h"
using namespace std;

template <class Key, class Value> class Key_Value{
	private:
		Key key;
		Value value;
	public:
		Key_Value(Key k, Value v){
			this.key = k;
			this.value = v;
		}
		Value getValue(){return value;}
		
		Key getKey(){return key;}

		void setValue(Value v){this.value = v;}

		void setKey(Key k){this.key = k;}

		bool operator==(Key_Value& k_v){ return (k_v.getKey() == this.key);} 

}


template  <class Key, class Value> class HashMap{

private:
	SList< Key_Value<Key,Value> > array*; 
	size_t size;
	
public:
	
	HashMap(){
		this.size = 10;
	}

	HashMap(size_t size){
		if(size_t > 0)
			this.size = size;
		else 
			this.size = 10;

		this->array = new SList< Key_Value> >[size];
	}
	
	~HashMap(){
		for(int i = 0; i < size; i){
			array[i].removeList();
		}
		delete array;

	}

	void insert(Key k, Value v){
		int modulo = k % this.size;
		array[modulo].insert( new KeyValue(k,v));
	}

	V getValue(key k){
		int modulo = k % this.size;
		Key_Value k_v = new Key_Value(k,new Value());
		return array[modulo].search(k_v).getValue();
	}

	void remove(key k){
		int modulo = k % this.size;
		Key_Value k_v = new Key_Value(k,new Value());
		array[modulo].remove(k_v);
	}


}

