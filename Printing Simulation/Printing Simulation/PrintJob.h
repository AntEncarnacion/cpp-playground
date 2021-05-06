#pragma once


class PrintJob 
{
private:
	int pages;	//	type of event: arrive, sign in, renew license, renew registration, and cope with the cashier. 
	int time;	//	arrival time in seconds
	int length;
	char type;	// type of event A for assigned, P for printed
	int printerNum;

public:
	PrintJob();
	~PrintJob();
	PrintJob(const Event);
	void setTime(int in);
	void setPages(int in);
	void setType(char in);
	int getTime() const;
	int getPages() const;
	int getLength() const;
	char getType() const;
	int getPrinterNum() const;

	bool operator ==(const PrintJob& right)const;
	bool operator !=(const PrintJob& right)const;
	bool operator <(const PrintJob& right)const;
	bool operator >(const PrintJob& right)const;

};

PrintJob::PrintJob()
{
}
PrintJob::PrintJob(const Event obj)
{
	this->time = obj.getTime();
	this->pages = obj.getPages();
	this->length = obj.getLength();
	this->type = obj.getType();
	this->printerNum = obj.getPrinterNum();
}

PrintJob::~PrintJob()
{
}
void PrintJob::setTime(int in)
{
	time = in;
}
void PrintJob::setPages(int in)
{
	pages = in;
	if (pages <= 10)
		length = pages / (10 / 60);
	else if (pages <= 20)
		length = pages / (5 / 60);
	else
		length = pages / (3 / 60);
}
void PrintJob::setType(char in)
{
	type = in;
}
int PrintJob::getPages() const
{
	return pages;
}
int PrintJob::getTime() const
{
	return time;
}
int PrintJob::getLength() const
{
	return length;
}
char PrintJob::getType() const
{
	return type;
}
int PrintJob::getPrinterNum() const
{
	return printerNum;
}

bool PrintJob::operator ==(const PrintJob& right)const
{
	return pages == right.getPages() && (time == right.getTime());
}
bool PrintJob::operator !=(const PrintJob& right)const
{
	return pages != right.getPages() && (time != right.getTime());
}
bool PrintJob::operator <(const PrintJob& right)const
{
	return pages < right.getPages()&& (time < right.getTime());
}
bool PrintJob::operator >(const PrintJob& right)const
{
	return pages > right.getPages() && (time > right.getTime());
}