package assignment06;
import java.lang.Iterable;

public interface MComp extends Iterable<MComp>{
	default void add(MComp mComp) {
		throw new UnsupportedOperationException();
	}
	default void remove(MComp mComp) {
		throw new UnsupportedOperationException();
	}
	default MComp getChild(int i) {
		throw new UnsupportedOperationException();
	}
	default String getName() {
		throw new UnsupportedOperationException();
	}
	default String getDescription() {
		throw new UnsupportedOperationException();
	}
	default double getPrice() {
		throw new UnsupportedOperationException();
	}
	default boolean isVegetarian() {
		throw new UnsupportedOperationException();
	}
	default void print() {
		throw new UnsupportedOperationException();
	}
}
