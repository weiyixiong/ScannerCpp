package com.htmlparser.jni;

public class Token {
	public static final int STRONG = 260;
	public static final int TEXT = 270;
	public static final int IMG = 268;
	public static final int HREF = 272;

	public int tag = 1;
	public String text;

	public int getTag() {
		return tag;
	}

	public void setTag(int tag) {
		this.tag = tag;
	}

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}

}
