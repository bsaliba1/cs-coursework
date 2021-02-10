package lab09;

import static org.junit.Assert.*;
import org.junit.Test;
import org.junit.Before;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Comparator;

public class BinaryTreeTester {
    private final List<Integer> data = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5, 0, -1, 2, 3));;
    private final Comparator<Integer> intComp = (i, j) -> i - j;
    private BinarySearchTree<Integer> ints;

    @Before
    public void setup() {
        ints = new BinarySearchTree<>(intComp);
        for (int i : data) {
            ints.insert(i);
        }
    }

    @Test
    public void insertFound() {
        for (int i : data) {
            assertNotNull(ints.find(i));
        }
    }

    @Test
    public void othersNotFound() {
        assertNull(ints.find(6));
        assertNull(ints.find(-3));
        assertNull(ints.find(-4));
    }

    @Test
    public void elemsFound() {
        List<Integer> elems = ints.getElements();
        for (int i : elems) {
            assertNotNull(ints.find(i));
        }
    }

    @Test
    public void elemsWereAdded() {
        List<Integer> elems = ints.getElements();
        assertEquals(7, elems.size());
        for (int i : elems) {
            assertNotNull(data.contains(i));
        }
    }

    @Test
    public void elemsCorrect() {
        List<Integer> elems = ints.getElements();
        for (int i : data) {
            assertTrue(elems.contains(i));
        }
    }

    @Test
    public void elemsInCorrectOrder() {
        List<Integer> elems = ints.getElements();
        for (int i = 1; i < elems.size(); i++) {
            assertTrue(elems.get(i-1) < elems.get(i));
        }
    }
}