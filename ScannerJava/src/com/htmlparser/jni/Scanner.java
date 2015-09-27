package com.htmlparser.jni;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;

public class Scanner {
	static {
		// 调用文件名为JNI Library.dll的动态库
		System.loadLibrary("libScannerCpp");
	}

	public static String changeCharset(String str, String newCharset)
			throws UnsupportedEncodingException {
		if (str != null) {
			// 用默认字符编码解码字符串。
			byte[] bs = str.getBytes();
			// 用新的字符编码生成字符串
			return new String(bs, newCharset);
		}
		return null;
	}

	public static void main(final String[] args) {
		StringBuilder html = readFile("C://parserTest//img.txt");
		StringBuilder html2 = readFile("C://code2.txt");
		// System.out.println(html);
		Scanner scanner = new Scanner();
		for (int i = 0; i < 100000; i++) {
			System.out.println("Scanner.main()"+i);
			ArrayList<Token> tokens = scanner.parseHTMl(html.toString());
			printToken(tokens);
			
			ArrayList<Token> tokens2 = scanner.parseHTMl(html2.toString());
			printToken(tokens2);

//			ArrayList<Token> tokens3 = scanner.parseHTMl(html2.toString());
//			printToken(tokens3);
//
//			ArrayList<Token> tokens4 = scanner.parseHTMl(html2.toString());
//			printToken(tokens4);
		}

	}

	private static void printToken(ArrayList<Token> tokens) {
		for (Token token : tokens) {
			switch (token.tag) {
			case Token.TEXT:
				System.out.println("text:" + token.text);
				break;
			case Token.STRONG:
				System.out.println("strong:" + token.text);
				break;
			case Token.HREF:
				System.out.println("href:" + token.text);
				break;
			case Token.IMG:
				System.out.println("img:" + token.text);
				break;

			default:
				break;
			}
		}
	}

	private static StringBuilder readFile(String fileName) {
		BufferedReader bf = null;
		try {
			bf = new BufferedReader(new InputStreamReader(new FileInputStream(
					fileName)));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		String line;
		StringBuilder html = new StringBuilder();
		try {
			while ((line = bf.readLine()) != null) {
				html.append(line);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return html;
	}

	// native方法声明
	public native ArrayList<Token> parseHTMl(String code);
}