/*
* Copyright (C) 2013 Nivis LLC.
* Email:   opensource@nivis.com
* Website: http://www.nivis.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3 of the License.
* 
* Redistribution and use in source and binary forms must retain this
* copyright notice.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "C022_WriteLongTag.h"

uint8_t Compose_C022_WriteLongTag_Req(C022_WriteLongTag_Req* request,
			ComposerContext* context, BinaryStream* toStream)
{
	context->cmdId = CMDID_C022_WriteLongTag;

	STREAM_WRITE_LATIN(toStream, request->longTag, sizeof(request->longTag));

	return RCS_N00_Success;
}

uint8_t Parse_C022_WriteLongTag_Req(C022_WriteLongTag_Req* request,
			ParserContext* context, BinaryStream* fromStream)
{
	#if defined(_DEBUG)
// 		if (fromStream->remainingBytes < C022_ReqSize)
// 			return RCS_E05_TooFewDataBytesReceived;
	#endif

	STREAM_READ_LATIN(fromStream, &request->longTag, sizeof(request->longTag));

	return RCS_N00_Success; //success
}

uint8_t Compose_C022_WriteLongTag_Resp(C022_WriteLongTag_Resp* response,
		ComposerContext* context, BinaryStream* toStream)
{
	context->cmdId = CMDID_C022_WriteLongTag;

	STREAM_WRITE_LATIN(toStream, response->longTag, sizeof(response->longTag));

	return RCS_N00_Success;
}

uint8_t Parse_C022_WriteLongTag_Resp(C022_WriteLongTag_Resp* response,
		ParserContext* context, BinaryStream* fromStream)
{

	#if defined(_DEBUG)
// 		if (fromStream->remainingBytes < C022_RespSize)
// 			return RCS_E05_TooFewDataBytesReceived;
	#endif

	STREAM_READ_LATIN(fromStream, &response->longTag, sizeof(response->longTag));

	return RCS_N00_Success; //success
}

