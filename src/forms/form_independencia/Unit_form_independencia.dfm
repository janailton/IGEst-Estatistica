object Form_independencia: TForm_independencia
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Teste de Independ'#234'ncia'
  ClientHeight = 320
  ClientWidth = 615
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 285
    Width = 74
    Height = 13
    Caption = 'Confian'#231'a (%):'
  end
  object StringGridIndependencia: TStringGrid
    Left = 8
    Top = 8
    Width = 599
    Height = 257
    Cursor = crIBeam
    DefaultColWidth = 60
    DefaultRowHeight = 20
    DoubleBuffered = False
    DragCursor = crIBeam
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs, goAlwaysShowEditor, goThumbTracking]
    ParentDoubleBuffered = False
    TabOrder = 0
  end
  object btnCalcular: TButton
    Left = 296
    Top = 287
    Width = 105
    Height = 25
    Caption = 'Calcular'
    TabOrder = 1
    OnClick = btnCalcularClick
  end
  object EditConfianca: TEdit
    Left = 121
    Top = 282
    Width = 136
    Height = 21
    TabOrder = 2
  end
end
