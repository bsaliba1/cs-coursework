package lab11;

import java.util.IllegalFormatFlagsException;

public class ParityCheckException extends IllegalFormatFlagsException{
	String message;
	public ParityCheckException(String aMessage){
		super(aMessage);
		this.message =aMessage;
	}
}
