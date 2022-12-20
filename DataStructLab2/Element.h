#pragma once

/**
 * \brief ������������ ���������� �� ������������� �������� ������.
 */
struct Element
{
	/**
	 * \brief ��������� �� ��������� ������� ������.
	 */
	Element* Next;
	/**
	 * \brief ��������� �� ���������� ������� ������.
	 */
	Element* Previous;
	/**
	 * \brief �������� �������� ������.
	 */
	int Data;
};