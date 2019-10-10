object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 182
  ClientWidth = 336
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 200
    Top = 32
    Width = 110
    Height = 13
    Caption = 'Ponto Inicial XoYoZ 0.0'
  end
  object Label2: TLabel
    Left = 200
    Top = 80
    Width = 105
    Height = 13
    Caption = 'Ponto Final XoYoZ 0.0'
  end
  object Edit1: TEdit
    Left = 24
    Top = 24
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 0
    Text = '0.0'
  end
  object Edit2: TEdit
    Left = 24
    Top = 51
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 1
    Text = '0.0'
  end
  object EditoZ: TEdit
    Left = 24
    Top = 78
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 2
    Text = '0.0'
    TextHint = 'Eixo oZ'
  end
end
