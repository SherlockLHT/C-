#ifndef PRINTERMANAGER_H
#define PRINTERMANAGER_H

#include <QObject>
#include <QList>

#include <list>

class PrinterManager : public QObject
{
	Q_OBJECT

public:
	PrinterManager(QObject *parent);
	~PrinterManager();

public:
	/*
	 * @brief	ʹ��Qt�ķ����õ���ǰ�������Ĭ�ϴ�ӡ��
	 * @return	Ĭ�ϴ�ӡ��������
	 */
	static QString GetDefaultPrinterByQt();

	/*
	 * @brief		ʹ��Windows API��ȡ��ǰ�������Ĭ�ϴ�ӡ��
	 * @param[out]	printer_name Ĭ�ϴ�ӡ������
	 * return		0:pass;��0:��ѯwindows API�Ĵ�����Ϣ
	 */
	static int GetDefaultPrinterByWindowsAPI(std::wstring* printer_name);

	/*
	 * @brief		ʹ��Qt�ķ�����ȡ��ǰ������ϵ����д�ӡ��
	 * @param[out]	all_printer	��ӡ���б�
	 */
	static void GetAllPrintersByQt(QList<QString>* all_printers);

	/*
	 * @brief		ʹ��windows API�ķ�����ȡ��ǰ������ϵ����д�ӡ��
	 * @param[out]	all_printers	��ӡ���б�
	 * return		0:pass;��0:��ѯwindows API�Ĵ�����Ϣ
	 */
	static int GetAllPrintersByWindowsAPI(std::list<std::wstring>* all_printers);
	
	/*
	 * @brief		ʹ��Qt�ķ������õ�ǰĬ�ϵĴ�ӡ��
	 * @param[in]	printer_name	��ӡ������
	 * @note		δʵ��	
	 */
	static void SetDefaultPrinterByQt(const QString& printer_name);

	/*
	 * @brief		ʹ��windows API���õ�ǰ��Ĭ�ϴ�ӡ��
	 * @param[in]	printer_name	��ӡ������
	 */
	static bool SetDefaultPrinterByWindowsAPI(const std::wstring& printer_name);

	/*
	 * @brief		ʹ��windows API��ӡ�ļ���ʹ��Ĭ�ϴ�ӡ��
	 * @param[in]	file	��Ҫ��ӡ���ļ�
	 */
	static bool PrinterFileByWindowsAPI(const std::wstring& file);
};

#endif // PRINTERMANAGER_H
