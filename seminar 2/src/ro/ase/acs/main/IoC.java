package ro.ase.acs.main;

import java.util.HashMap;
import java.util.Map;

public class IoC {

	static Map<Class<?>, Class<?>> map = new HashMap<>();
	
	public void register(Class<?> contract, Class<?> implementation) {
		if(!map.containsKey(contract)) {
			map.put(contract, implementation);
		}
	}
	
	public static Class<?> resolve(Class<?> c) {
		Class object = map.get(c);
		return object;
	}
}
